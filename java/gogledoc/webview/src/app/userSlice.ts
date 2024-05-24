import {createSlice, PayloadAction} from '@reduxjs/toolkit';
import {RootState} from "./store.ts";

import getRandomColor from "../utils/colorGenerator.ts";

export interface UserState {
  username: string;
  color: string;
  status: 'idle' | 'loading' | 'failed';
}

const initialState: UserState = {
  username: "",
  color: "",
  status: 'idle',
};

export const userSlice = createSlice({
  name: 'user',
  initialState,
  reducers: {
    login: (state, action: PayloadAction<string>) => {
      state.username = action.payload;
      state.color = getRandomColor();
    },
    logout: (state) => {
      state.username = "";
    }
  },
});

export const {login, logout} = userSlice.actions;

export const selectUser = (state: RootState) => {
  return state.user.username;
};

export default userSlice.reducer;
