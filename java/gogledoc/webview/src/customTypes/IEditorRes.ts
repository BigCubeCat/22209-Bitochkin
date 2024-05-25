interface IEditorResData {
  begin: number;
  content: string;
  changes: boolean;
  replace: boolean;
}

// Команда с бакенда
interface IEditorRes {
  unixtime: number;
  update: boolean;
  state: string[];
  data: IEditorResData | null;
}

export default IEditorRes;