import {deepPurple} from "@mui/material/colors";
import Avatar from "@mui/material/Avatar";

const UserAvatar = ({name}: { name: string }) =>
  <Avatar sx={{bgcolor: deepPurple[500]}}>{name}</Avatar>

export default UserAvatar;