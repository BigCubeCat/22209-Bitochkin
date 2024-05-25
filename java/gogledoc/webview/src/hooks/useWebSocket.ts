import {SERVER_ADDRESS} from "../../CONST.ts";
import {useEffect, useState} from "react";
import {WebSocket} from "vite";
import CloseEvent = WebSocket.CloseEvent;
import {useDispatch} from "react-redux";
import {emptyRequest, selectRequest, setResponse} from "../app/editorSlice.ts";
import {useAppSelector} from "../app/hooks.ts";

export default function useWebSocket() {
  const dispatch = useDispatch();
  const currentRequest = useAppSelector(selectRequest);
  const [socket, setSocket] = useState();

  useEffect(() => {
    if (!socket) return;
    socket.onopen = () => console.log('Соединение установлено');
    socket.onmessage = function (event) {
      console.log(`Получено сообщение: ${event.data}`);
      dispatch(setResponse(event.data));
    };
    socket.onclose = (event: CloseEvent) => console.log('Соединение закрыто ' + event.target);
    socket.onerror = (error)  => console.log(`Ошибка: ${error}`);
  }, [socket]);

  useEffect(() => {
    if (!socket) return;
    if (currentRequest) {
      socket.send(JSON.stringify(currentRequest));
      dispatch(emptyRequest());
    }
  }, [currentRequest]);

  useEffect(() => {
  }, []); // TODO: Сделать чтение stat-а на предмет новых сообщений
  return {socket, setSocket};
}