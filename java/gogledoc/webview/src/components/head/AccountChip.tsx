import {Paper, Typography} from "@mui/material";
import Avatar from "@mui/material/Avatar";
import {useDispatch} from "react-redux";
import {logout} from "../../app/userSlice.ts";

export default function AccountChip(props: { name: string, color: string }) {
  const dispatch = useDispatch();

  const handleClick = () => {
    dispatch(logout());
  };

  return <Paper
    sx={{margin: 1, display: "flex"}}
    elevation={0}
    onClick={() => handleClick()}
  >
    <Typography
      component="h6"
      sx={{flexGrow: 1, margin: 1, marginRight: 2}}
    >{props.name}
    </Typography>
    <Avatar
      sx={{bgcolor: "black"}}
    />
  </Paper>
}
