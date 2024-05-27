import {AvatarGroup} from "@mui/material";
import UserAvatar from "./UserAvatar.tsx";
import IUserCursor from "../../customTypes/IUserCursor.ts";

export default function AvaGroup({users}: { users: IUserCursor[] }) {
  return <AvatarGroup sx={{margin: 1}} max={5}>
    {users.map(user => <UserAvatar name={user.username} color={user.color}/>)}
  </AvatarGroup>
}