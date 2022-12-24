# CustomConfig
A class for managing config files, works as (Key:Value) for each line in a text file
//Reading
CustomConfig cfg;
cfg.readData("config.txt");
cfg.printAllData();
std::string ip = cfg.getDataByDescription("ip");
std::string port = cfg.getDataByDescription("port");
//Writing
CustomConfig cfg;
cfg.writeData("ip", "127.0.0.1");
cfg.writeData("port", "12312");
cfg.saveToFile("config.txt");
//
