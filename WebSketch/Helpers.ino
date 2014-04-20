
void splitString(String text, char delimeter, String out[]){
  String currentWord = "";
  int count = 0;
  for (int i =0; i < text.length(); i++) {
    if (text.charAt(i) == delimeter){
      if (currentWord.length() > 0){
        out[count] = currentWord;
        currentWord = "";
        count++;
      }
    } else {
      currentWord = currentWord + text.charAt(i);
    }
  }
  if (currentWord.length() > 0){
        out[count] = currentWord;
  }
}
