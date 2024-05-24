import {SERVER_ADDRESS} from "../../CONST.ts";
import {useEffect, useState} from "react";
import {WebSocket} from "vite";
import CloseEvent = WebSocket.CloseEvent;

export default function useWebSocket() {
  const [socket] = useState(
    new WebSocket(SERVER_ADDRESS)
  );

  useEffect(() => {
    socket.onopen = function () {
      console.log('Соединение установлено');
    };

    socket.onmessage = function (event) {
      console.log(`Получено сообщение: ${event.data}`);
    };

    socket.onclose = function (event: CloseEvent) {
      console.log('Соединение закрыто ' + event.target);
    };

    socket.onerror = function (error) {
      console.log(`Ошибка: ${error}`);
    };

  }, []);

  const sendMessage = (text: string) => {
    socket.send(text);
  };

  useEffect(() => {
  }, []); // TODO: Сделать чтение stat-а на предмет новых сообщений

  return {sendMessage};
}