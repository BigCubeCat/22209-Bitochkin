interface IDiff {
  type: "J" | "R";
  content: string;
  begin: number;
  end: number;
}

export default function diffContent(prev: string, next: string) : IDiff {
  const res: IDiff = {type: "R"} as IDiff;
  if (next.startsWith(prev)) {
    res.begin = prev.length + 1;
    res.end = prev.length + 2;
    res.content = next.substring(prev.length - 1, next.length);
  } else if (next.endsWith(prev)) {
    res.begin = 0;
    res.end = 0;
    res.content = next.substring(0, next.length - prev.length);
  } else {
    // Заменяем вообще все. У меня сроки горят((
    res.begin = 0;
    res.end = prev.length + 2;
    res.content = next;
  }
  return res;
}