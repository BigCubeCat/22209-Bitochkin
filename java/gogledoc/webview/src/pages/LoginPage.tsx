import {Box} from "@mui/material";
import LoginForm from "../components/main/LoginForm.tsx";

export default function LoginPage() {
  return <Box sx={{
    width: "100%",
    height: "90vh",
    display: "flex",
    justifyContent: "center",
    alignItems: "center"
  }}>
    <LoginForm filename="data.txt"/>
  </Box>
}

