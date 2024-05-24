import {Paper} from "@mui/material";
import React, {useRef} from "react";
import useEditor from "../../hooks/useEditor.ts";

import "./Editor.css";

export default function Editor() {
  const editorHook = useEditor();
  const textAreaRef = useRef<HTMLTextAreaElement>(null);
  return <Paper className="Paper" sx={{margin: 1}}>
    <textarea
      className={"Editor"}
      ref={textAreaRef}
      value={editorHook.content}
      onChange={(event: React.ChangeEvent<HTMLTextAreaElement>) => {
        editorHook.editContent(event.target.value);
        console.log("selection start = " + event.target.selectionStart);
        console.log(event.target.value);
      }}
    />
  </Paper>
}
