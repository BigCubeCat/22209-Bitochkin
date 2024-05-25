import {useDispatch} from "react-redux";
import useWebSocket from "react-use-websocket";
import {SERVER_ADDRESS} from "../../CONST.ts";
import IEditorRes from "../customTypes/IEditorRes.ts";
import {emptyRequest, loadContent, selectRequest, setRequest} from "../app/editorSlice.ts";
import {useEffect} from "react";
import {useAppSelector} from "../app/hooks.ts";
import IEditorReq from "../customTypes/IEditorReq.ts";
import {setUserList} from "../app/userSlice.ts";

export default function useConn() {
  const editorReq = useAppSelector(selectRequest);

  const dispatch = useDispatch();
  const {sendJsonMessage} = useWebSocket(SERVER_ADDRESS, {
    onOpen: () => {
      console.log('WebSocket connection established.');
      const helloMsg = {begin: 0, end: 0, unixtime: 0, type: "R", content: "", user: ""} as IEditorReq;
      dispatch(setRequest(helloMsg));
    },
    onMessage: (event: MessageEvent<string>) => {
      const resp: IEditorRes = JSON.parse(event.data);
      dispatch(loadContent(resp));
      dispatch(setUserList(resp.state))
    },
    shouldReconnect: () => true,
  });

  useEffect(() => {
    if (!editorReq) return;
    sendJsonMessage(editorReq);
    dispatch(emptyRequest());
  }, [editorReq]);

  return {};
}
