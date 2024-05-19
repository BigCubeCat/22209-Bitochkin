import {Box} from "@mui/material";
import Editor from "../components/editor/Editor.tsx";
import Sidebar from "../components/sidebar/Sidebar.tsx";

export default function MainPage() {
  return <Box sx={{width: "100%", height: "100%", display: "flex"}}>
    <Editor/>
    <Sidebar />
  </Box>
}