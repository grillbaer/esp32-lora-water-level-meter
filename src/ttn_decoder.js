function BytesToInt16(b0, b1) {
  var word = (b0 << 8) + (b1 << 0);
  if ((word & 0x8000) == 0x8000) {
    word = -(~word & 0xffff) - 1;
  }

  return word;
}

function Decoder(bytes, port) {
  var decoded = {};
  decoded.levelMeter = BytesToInt16(bytes[0], bytes[1]) / 1000;
  decoded.batteryVolt = BytesToInt16(bytes[2], bytes[3]) / 1000;

  return decoded;
}
