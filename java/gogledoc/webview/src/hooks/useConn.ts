import {useDispatch} from "react-redux";
import useWebSocket from "react-use-websocket";
import {SERVER_ADDRESS} from "../../CONST.ts";
import IEditorRes from "../customTypes/IEditorRes.ts";
import {emptyRequest, selectRequest, setResponse} from "../app/editorSlice.ts";
import {useEffect} from "react";
import {useAppSelector} from "../app/hooks.ts";

export default function useConn() {
  const editorReq = useAppSelector(selectRequest);

  const dispatch = useDispatch();
  const {sendJsonMessage} = useWebSocket(SERVER_ADDRESS, {
    onOpen: () => {
      console.log('WebSocket connection established.');
    },
    onMessage: (event: MessageEvent<string>) => {
      console.log(event.data);
      const resp: IEditorRes = JSON.parse(event.data);
      dispatch(setResponse(resp));
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
