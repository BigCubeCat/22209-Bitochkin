import {Paper} from "@mui/material";
import React, {useRef} from "react";
import useEditor from "../../hooks/useEditor.ts";

export default function Editor() {
  const editorHook = useEditor();
  const textAreaRef = useRef<HTMLTextAreaElement>(null);
  return <Paper className="Paper">
    <textarea
      ref={textAreaRef}
      value={editorHook.renderContent}
      onChange={(event: React.ChangeEvent<HTMLTextAreaElement>) => {
        editorHook.setCursorList([{position: event.target.selectionEnd, color: "red"}]);
        editorHook.editContent(event.target.value);
        console.log("selection start = " + event.target.selectionStart);
        console.log(event.target.value);
      }}
    />
    <div dangerouslySetInnerHTML={{__html: editorHook.renderContent}}></div>
  </Paper>
}
