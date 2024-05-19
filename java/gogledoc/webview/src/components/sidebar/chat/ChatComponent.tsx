import {Box} from "@mui/material";
import Messages from "./Messages.tsx";
import InputMessage from "./InputMessage.tsx";

export default function ChatComponent() {
  return <Box sx={{margin: 1, display: "flex", flexDirection: "column-reverse"}}>
    <InputMessage />
    <Messages />
  </Box>
}