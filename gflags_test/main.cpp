#include <iostream>
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;

DEFINE_string(confPath, "../conf/setup.ini", "program configure file.");
DEFINE_int32(port, 9090, "program listen port");
DEFINE_bool(daemon, true, "run daemon mode");
DEFINE_string(obu_ip, "192.168.10.123", "OBU IP");
DEFINE_string(svb_ip, "192.168.10.6", "SVB IP");
DEFINE_bool(security_flag, false, "security enable flag");




int main(int argc,char *argv[])
{

    google::SetVersionString("1.0");
    google::SetUsageMessage("Usage : ./gft ");
    google::ParseCommandLineFlags(&argc, &argv, true);
    //cout << argc << "||" <<argv[0] << endl;

    google::InitGoogleLogging("gft");

    FLAGS_logbufsecs = 0;
    // set the log file to 100MB
    FLAGS_max_log_size = 1;
    FLAGS_stop_logging_if_full_disk = true;
    google::SetStderrLogging(google::GLOG_INFO);//GLOG_INFO,GLOG_WARNING,GLOG_ERROR,GLOG_FATAL
    
    string path = "../log";
    string dest_dir = path + "/info/";
    cout << dest_dir << endl;
    google::SetLogDestination(google::GLOG_INFO, dest_dir.c_str());
    dest_dir = path + "/warning/";
    google::SetLogDestination(google::GLOG_WARNING, dest_dir.c_str());
    dest_dir = path + "/error/";
    google::SetLogDestination(google::GLOG_ERROR, dest_dir.c_str());
    dest_dir = path + "/fatal/";
    google::SetLogDestination(google::GLOG_FATAL, dest_dir.c_str());    



    LOG(INFO) <<"port = " << FLAGS_port;
    LOG(INFO) << "security_flag = " << FLAGS_security_flag;
    LOG(INFO) << "flagfile = " << FLAGS_confPath;


    while(1)
    {
        LOG(INFO) << "google log first info level message!";
        sleep(10);
    }



    
    google::ShutdownGoogleLogging();
    google::ShutDownCommandLineFlags();
    return 0;
}
