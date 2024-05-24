import { configureStore, ThunkAction, Action } from '@reduxjs/toolkit';
import editorReducer from "./editorSlice";

export const store = configureStore({
  reducer: {
    editor: editorReducer,
  },
});

export type AppDispatch = typeof store.dispatch;
export type RootState = ReturnType<typeof store.getState>;
export type AppThunk<ReturnType = void> = ThunkAction<
  ReturnType,
  RootState,
  unknown,
  Action<string>
>;
