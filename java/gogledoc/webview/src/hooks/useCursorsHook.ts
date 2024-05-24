import {useState} from "react";
import TUserCursor from "../customTypes/TUserCursor.ts";

export default function useCursorsHook() {
  const [cursorList, setCursorList] = useState<TUserCursor[]>([]);
  const [currentUser, setCurrentUser] = useState<string>("");
  // TODO: useEffect to load user login from redux

  const setMyCursorPosition = (pos: number) => {
    for (let i = 0; i < pos; i++) {
      if (cursorList[i].username == currentUser) {
        cursorList[i].index = pos;
        setCursorList(cursorList);
        return;
      }
    }
    cursorList.push({username: currentUser, index: pos, color: "red"});
  };

  return {
    cursorList, setMyCursorPosition,
  }
}
