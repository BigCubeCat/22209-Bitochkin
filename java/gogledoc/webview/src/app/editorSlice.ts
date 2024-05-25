import {createSlice, PayloadAction} from '@reduxjs/toolkit';
import {RootState} from "./store.ts";
import IEditorReq from "../customTypes/IEditorReq.ts";

/*
По сути этот Slice нужен для коммуникации между useEditor и useWebSocket
 */

export interface EditorState {
  request: IEditorReq | null;
  response: object | null;
  status: 'idle' | 'loading' | 'failed';
}

const initialState: EditorState = {
  request: null,
  response: null,
  status: 'idle',
};

export const editorSlice = createSlice({
  name: 'editor',
  initialState,
  reducers: {
    setRequest: (state, action: PayloadAction<IEditorReq>) => {
      state.request = action.payload;
      console.log("resuest = ", state.request);
    },
    setResponse: (state, action: PayloadAction<object>) => {
      state.response = action.payload;
    },
    emptyRequest: (state) => {
      state.request = null;
    },
    emptyResponse: (state) => {
      state.response = null;
    }
  },
});

export const {
  setRequest, setResponse, emptyResponse, emptyRequest
} = editorSlice.actions;

export const selectRequest = (state: RootState) => {
  return state.editor.request;
};

export const selectResponse = (state: RootState) => {
  return state.editor.response;
};

export default editorSlice.reducer;
