import {useState} from "react";

export default function useEditor() {
  // Original content
  const [content, setContent] = useState("");
  // Content to render

  const editContent = (content: string) => {
    setContent(content);
  }

  return {
    editContent, content
  }
}