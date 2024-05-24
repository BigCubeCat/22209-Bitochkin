import {Paper} from "@mui/material";
import AvaGroup from "../head/AvaGroup.tsx";
import ChatComponent from "./chat/ChatComponent.tsx";

export default function Sidebar() {
  return <Paper sx={{
    display: "flex",
    flexDirection: "column",
    marginLeft: 4,
    minWidth: 200,
    alignItems: "start"
  }}>
    <AvaGroup users={["egor", "ivan", "root", "bigcubecat", "igor", "man", "child", "guy"]} />
    <ChatComponent />
  </Paper>
}