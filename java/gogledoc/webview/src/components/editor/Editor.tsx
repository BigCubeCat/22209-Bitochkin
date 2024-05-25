import {Paper} from "@mui/material";
import React, {useRef} from "react";
import useEditor from "../../hooks/useEditor.ts";

import "./Editor.css";
import {useAppSelector} from "../../app/hooks.ts";
import {selectRequest} from "../../app/editorSlice.ts";
import {TIMEOUT} from "../../CONST.ts";

export default function Editor() {
  const editorReq = useAppSelector(selectRequest);
  const editorHook = useEditor();

  const textAreaRef = useRef<HTMLTextAreaElement>(null);

  setInterval(() => {
    if (!editorReq) {
      const cursorPos = textAreaRef.current?.selectionStart;
      if (cursorPos !== undefined) {
        editorHook.jumpCursor(cursorPos);
      }
    }
  }, TIMEOUT);

  return <Paper className="Paper" sx={{margin: 1}}>
    <textarea
      className={"Editor"}
      ref={textAreaRef}
      value={editorHook.content}
      onChange={(event: React.ChangeEvent<HTMLTextAreaElement>) => {
        editorHook.editContent({
          prevContent: editorHook.content,
          nextContent: event.target.value || "",
        });
      }}
    />
  </Paper>
}
