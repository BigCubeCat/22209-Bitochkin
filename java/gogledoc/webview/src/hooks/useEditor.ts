import {useState} from "react";
import {useDispatch} from "react-redux";
import {setRequest} from "../app/editorSlice.ts";
import {selectUser} from "../app/userSlice.ts";
import {useAppSelector} from "../app/hooks.ts";
import {JUMP_TYPE} from "../../CONST.ts";
import diffContent from "../utils/diff.ts";

interface IContentChange {
  prevContent: string;
  nextContent: string;
}

export default function useEditor() {
  const dispatch = useDispatch();
  const user = useAppSelector(selectUser);

  // Original content
  const [content, setContent] = useState("");

  const jumpCursor = (position: number) => {
    dispatch(setRequest({
      user: user, begin: position, end: position, content: "", type: JUMP_TYPE
    }));
  };

  const editContent = (contentChange: IContentChange) => {
    const diff = diffContent(contentChange.prevContent, contentChange.nextContent);
    dispatch(setRequest({
      user: user, ...diff
    }));
    setContent(contentChange.nextContent);
  }

  return {
    editContent, content,
    jumpCursor
  }
}