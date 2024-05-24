import {Box, Typography} from "@mui/material";
import Avatar from "@mui/material/Avatar";

export default function AccountChip(props: { name: string, color: string }) {
  return <Box sx={{margin: 1, display: "flex"}}>
    <Typography component="h6" sx={{flexGrow: 1, margin: 1}}>{props.name}</Typography>
    <Avatar sx={{bgcolor: "black"}} ></Avatar>
  </Box>
}
