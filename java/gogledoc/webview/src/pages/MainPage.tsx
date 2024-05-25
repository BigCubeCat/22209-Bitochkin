import {Box} from "@mui/material";
import Editor from "../components/editor/Editor.tsx";
import Head from "../components/head/Head.tsx";
import {useAppSelector} from "../app/hooks.ts";
import {selectUser} from "../app/userSlice.ts";
import {Redirect} from "wouter";
import useWebSocket from "../hooks/useWebSocket.ts";
import {useEffect} from "react";
import {WebSocket} from "vite";
import {SERVER_ADDRESS} from "../../CONST.ts";

export default function MainPage() {
  const {setSocket} = useWebSocket();
  useEffect(() =>{
    setSocket(new WebSocket((SERVER_ADDRESS)));
  }, []);
  const username = useAppSelector(selectUser);
  if (!username) {
    return <Redirect to="/login" />;
  }
  return <Box sx={{
    width: "97vw", height: "95vh", alignItem: "center",
  }}>
    <Head/>
    <Editor/>
  </Box>
}