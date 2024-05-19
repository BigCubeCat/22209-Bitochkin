import {Box, IconButton, TextField} from "@mui/material";
import {Send} from "@mui/icons-material";


export default function InputMessage() {
  const send = () => {

  }
  return <Box sx={{display: "flex"}}>
    <TextField />
    <IconButton color="primary" onClick={send}>
      <Send />
    </IconButton>
  </Box>
}