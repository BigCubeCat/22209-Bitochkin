import {createSlice, PayloadAction} from '@reduxjs/toolkit';
import {RootState} from "./store.ts";

export interface EditorState {
  content: string;
  status: 'idle' | 'loading' | 'failed';
}

const initialState: EditorState = {
  content: "",
  status: 'idle',
};

export const editorSlice = createSlice({
  name: 'user',
  initialState,
  reducers: {
    setContent: (state, action: PayloadAction<string>) => {
      state.content = action.payload;
    },
  },
});

export const {setContent} = editorSlice.actions;

export const selectContent = (state: RootState) => {
  return state.editor.content;
};

export default editorSlice.reducer;
