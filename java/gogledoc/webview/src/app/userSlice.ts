import {createSlice, PayloadAction} from '@reduxjs/toolkit';
import {RootState} from "./store.ts";

import getRandomColor from "../utils/colorGenerator.ts";
import IUserCursor from "../customTypes/IUserCursor.ts";

export interface UserState {
  user: IUserCursor;
  status: 'idle' | 'loading' | 'failed';
}

const initialState: UserState = {
  user: {position: 0, color: "balck", username: ""},
  status: 'idle',
};

export const userSlice = createSlice({
  name: 'user',
  initialState,
  reducers: {
    login: (state, action: PayloadAction<string>) => {
      state.user.username = action.payload;
      state.user.color = getRandomColor();
    },
    logout: (state) => {
      state.user.username = "";
    },

  },
});

export const {
  login,
  logout,
} = userSlice.actions;

export const selectUser = (state: RootState) => {
  return state.user.user.username;
};

export default userSlice.reducer;
