import {deepPurple} from "@mui/material/colors";
import Avatar from "@mui/material/Avatar";

const UserAvatar = ({name, color}: { name: string, color?: string }) =>
  <Avatar sx={{bgcolor: color ? color : deepPurple[500]}}>{name}</Avatar>

export default UserAvatar;