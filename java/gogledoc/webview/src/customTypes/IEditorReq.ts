// Команда которая направится в бэк
interface IEditorReq {
  user: string;
  type: string;
  content: string;
  begin: number;
  end: number;
  unixtime: number;
}

export default IEditorReq;