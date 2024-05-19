import {Box} from "@mui/material";
import LoginForm from "../components/main/LoginForm.tsx";

export default function LoginPage() {
  return <Box sx={{width: "100%", height: "100%"}}>
    <LoginForm filename="data.txt" />
  </Box>
}

