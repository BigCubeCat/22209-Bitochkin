import {Paper} from "@mui/material";
import AvaGroup from "./AvaGroup.tsx";
import {useAppSelector} from "../../app/hooks.ts";
import AccountChip from "./AccountChip.tsx";
import {selectUser, selectUserList} from "../../app/userSlice.ts";

export default function Head() {
  const username = useAppSelector(selectUser);
  const userList = useAppSelector(selectUserList);
  return <Paper sx={{margin: 1, display: "flex", justifyContent: "space-between"}}>
    <AvaGroup users={userList}/>
    <AccountChip name={username} color={'black'} />
  </Paper>
}