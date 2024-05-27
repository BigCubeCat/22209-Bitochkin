export default function getUnixtime() {
  let value = (+new Date()) % 30000000; // Год
  value = Math.floor(value / 100); // чтобы небыло двойников
  return value;
}