class Logger{
public:
  Logger() {}
  bool shouldPrintMessage(int timestamp, string message) {
    if(m.find(message)==m.end()){
      m[message]=max(m[message], timestamp);
      return true;
    }
    if(m[message]-timestamp>=10){
      m[message]=timestamp;
      return true;
    }
    return false;
  }
private:
  unordered_map<string,int> m;
}
