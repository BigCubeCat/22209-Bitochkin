import {createSlice, PayloadAction} from '@reduxjs/toolkit';
import {RootState} from "./store.ts";
import IEditorReq from "../customTypes/IEditorReq.ts";
import IEditorRes from "../customTypes/IEditorRes.ts";
import IUserCursor from "../customTypes/IUserCursor.ts";
import getRandomColor from "../utils/colorGenerator.ts";

/*
По сути этот Slice нужен для коммуникации между useEditor и useConn
 */

export interface EditorState {
  unixtime: number; // Last version
  content: string;
  request: IEditorReq | null;
  response: IEditorRes | null;
  userList: IUserCursor[];
  status: 'idle' | 'loading' | 'failed';
}

const initialState: EditorState = {
  unixtime: 0,
  content: "",
  request: null,
  response: null,
  userList: [],
  status: 'idle',
};

export const editorSlice = createSlice({
  name: 'editor',
  initialState,
  reducers: {
    setRequest: (state, action: PayloadAction<IEditorReq>) => {
      state.request = action.payload;
      console.log("request to send: ", state.request);
    },
    setResponse: (state, action: PayloadAction<IEditorRes>) => {
      state.response = action.payload;
    },
    emptyRequest: (state) => {
      state.request = null;
    },
    emptyResponse: (state) => {
      state.response = null;
    },
    setContent: (state, action: PayloadAction<string>) => {
      state.content = action.payload;
    },
    loadContent: (state, action: PayloadAction<IEditorRes>) => {
      const res = action.payload;
      if (res.update) {
        if (res.unixtime != state.unixtime) {
          console.log("ut", res.unixtime, state.unixtime);
          if (res.data) {
            console.log("content = " + state.content + "\t" + res.data.content);
            if (res.data.begin == -1) {
              state.content = state.content + res.data.content
            } else if (res.data.begin == 0) {
              state.content = res.data.content + state.content;
            } else {
              state.content = res.data.content;
            }
            state.unixtime = res.unixtime; // Маркируем версию
          }
        }
      }
      const list = state.userList;
      for (let i = 0; i < res.state.length; ++i) {
        const item = res.state[i].split(":");
        if (list.filter((element) => (element.username == item[0])).length == 0) {
          list.push({
            username: item[0], color: getRandomColor(), position: Number(item[1])
          });
        }
      }
      state.userList = list;
    }
  }
});

export const {
  setRequest,
  setResponse,
  emptyResponse,
  emptyRequest,
  setContent,
  loadContent,
} = editorSlice.actions;

export const selectRequest = (state: RootState) => {
  return state.editor.request;
};

export const selectResponse = (state: RootState) => {
  return state.editor.response;
};

export const selectVersion = (state: RootState) => {
  return state.editor.unixtime;
}

export const selectContent = (state: RootState) => {
  return state.editor.content;
}

export const selectUserList = (state: RootState) => {
  return state.editor.userList;
}

export default editorSlice.reducer;
