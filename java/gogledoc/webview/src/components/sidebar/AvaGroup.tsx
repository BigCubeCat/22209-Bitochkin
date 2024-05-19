import { AvatarGroup } from "@mui/material";
import UserAvatar from "./UserAvatar.tsx";

export default function AvaGroup({users}: {users: string[]}) {
  return <AvatarGroup sx={{margin: 1}} max={4}>{users.map(user => <UserAvatar name={user} />)}</AvatarGroup>
}