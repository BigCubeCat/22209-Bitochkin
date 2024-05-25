import {createSlice, PayloadAction} from '@reduxjs/toolkit';
import {RootState} from "./store.ts";

import getRandomColor from "../utils/colorGenerator.ts";
import IUserCursor from "../customTypes/IUserCursor.ts";

export interface UserState {
  user: IUserCursor;
  userList: IUserCursor[];
  status: 'idle' | 'loading' | 'failed';
}

const initialState: UserState = {
  user: {position: 0, color: "balck", username: ""},
  userList: [],
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
    setUserList: (state, action: PayloadAction<string[]>) => {
      const list = state.userList;
      for (let i = 0; i < action.payload.length; ++i) {
        const item = action.payload[i].split(":");
        if (list.filter((element) => (element.username == item[0])).length == 0) {
          list.push({
            username: item[0], color: getRandomColor(), position: Number(item[1])
          });
        }
      }
      state.userList = list;
    }
  },
});

export const {
  login,
  logout,
  setUserList
} = userSlice.actions;

export const selectUser = (state: RootState) => {
  return state.user.user.username;
};

export const selectUserList = (state: RootState) => {
  return state.user.userList;
}

export default userSlice.reducer;
