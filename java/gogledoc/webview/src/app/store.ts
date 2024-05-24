import { configureStore, ThunkAction, Action } from '@reduxjs/toolkit';
import editorReducer from "./editorSlice";
import userReducer from "./userSlice";

export const store = configureStore({
  reducer: {
    editor: editorReducer,
    user: userReducer,
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
