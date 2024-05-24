import {Paper} from "@mui/material";
import AvaGroup from "./AvaGroup.tsx";
import {useAppSelector} from "../../app/hooks.ts";
import AccountChip from "./AccountChip.tsx";
import {selectUser} from "../../app/userSlice.ts";

export default function Head() {
  const username = useAppSelector(selectUser);
  return <Paper sx={{margin: 1, display: "flex", justifyContent: "space-between"}}>
    <AvaGroup users={["egor", "ivan", "root", "bigcubecat", "igor", "man", "child", "guy"]}/>
    <AccountChip name={username} color={'black'} />
  </Paper>
}