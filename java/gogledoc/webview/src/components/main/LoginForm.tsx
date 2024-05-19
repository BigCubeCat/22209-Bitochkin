import {Box, Button, Paper, TextField, Typography} from "@mui/material";

import "./main.css";
import {ChangeEvent, useState} from "react";
import {Redirect} from "wouter";

export default function LoginForm(props: { filename: string }) {
  const [username, setUsername] = useState("");
  const [loggined, setLoggined] = useState(false);

  const handleClick = () => {
    if (username !== "") {
      // TODO: check username
      setLoggined(true);
    }
  };

  if (loggined) return <Redirect to="/"/>;

  return <Paper sx={{width: 300, padding: 5}}>
    <Box sx={{display: "flex", justifyContent: "space-between", flexDirection: "row"}}>
      <Typography variant="h6" component="div">Login to edit file:</Typography>
      <Typography variant="h6" component="div" sx={{color: "limegreen"}}>{props.filename}</Typography>
    </Box>
    <TextField
      sx={{
        width: "100%",
        marginTop: 8,
      }}
      required
      id="name-input"
      label="username"
      defaultValue=""
      value={username}
      onChange={
        (event: ChangeEvent<HTMLTextAreaElement | HTMLInputElement>) => setUsername(event.target.value)
      }
    />
    <Button
      sx={{width: "100%", marginTop: 4}}
      variant="contained"
      onClick={handleClick}
    >
      connect
    </Button>
  </Paper>
}