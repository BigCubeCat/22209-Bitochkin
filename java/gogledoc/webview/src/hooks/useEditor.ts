import {useState} from "react";

type UserCursor = {
  position: number;
  color: string
};

export default function useEditor() {
  // Original content
  const [content, setContent] = useState("");
  // Content to render
  const [renderContent, setRenderContent] = useState("");
  // user cursors
  const [cursorList, setCursorList] = useState<UserCursor[]>([]);

  const updateRender = () => {
    const newContent = Array.from(content);
    for (let i = newContent.length; i >= 0; --i) {
      for (let j = 0; j < cursorList.length; j++) {
        if (i == cursorList[j].position) {
          newContent.splice(
            i, 0, "<Cursor color=" + cursorList[j].color + " />"
          );
        }
      }
    }
    setRenderContent(newContent.join(""));
  }

  const editContent = (content: string) => {
    setContent(content);
    updateRender();
  }

  return {
    editContent, renderContent, setCursorList
  }
}