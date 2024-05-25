import {useDispatch} from "react-redux";
import {selectContent, setRequest} from "../app/editorSlice.ts";
import {selectUser} from "../app/userSlice.ts";
import {useAppSelector} from "../app/hooks.ts";
import {JUMP_TYPE} from "../../CONST.ts";
import diffContent from "../utils/diff.ts";
import getUnixtime from "../utils/getUnixtime.ts";

interface IContentChange {
  prevContent: string;
  nextContent: string;
}

export default function useEditor() {
  const dispatch = useDispatch();
  const user = useAppSelector(selectUser);

  const content = useAppSelector(selectContent);

  const jumpCursor = (position: number) => {
    dispatch(setRequest({
      user: user, begin: position, end: position, content: "", type: JUMP_TYPE, unixtime: getUnixtime()
    }));
  };

  const editContent = (contentChange: IContentChange) => {
    const diff = diffContent(contentChange.prevContent, contentChange.nextContent);
    console.log(getUnixtime());
    dispatch(setRequest({
      user: user, unixtime: getUnixtime(), ...diff
    }));
  }

  return {
    editContent, content,
    jumpCursor
  }
}