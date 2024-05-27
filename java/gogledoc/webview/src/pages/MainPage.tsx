import {Box} from "@mui/material";
import Editor from "../components/editor/Editor.tsx";
import Head from "../components/head/Head.tsx";
import {useAppSelector} from "../app/hooks.ts";
import {selectUser} from "../app/userSlice.ts";
import {Redirect} from "wouter";

import useConn from "../hooks/useConn.ts";


export default function MainPage() {
  useConn();

  const username = useAppSelector(selectUser);
  if (!username) {
    return <Redirect to="/login"/>;
  }
  return <Box sx={{
    width: "97vw", height: "95vh", alignItem: "center",
  }}>
    <Head/>
    <Editor/>
  </Box>
}