# Server

Используется JSON

## Request

```json
{
  "user": "<username>",
  "type": "i" | "r" | "d" | "c" | "u" | "m",
  "position": "положение курсора"
}
```

## Response

Ответ всегда содержит положение курсоров.

```json
{
  "state": ["<username>:<position>"],
  ""
}
```