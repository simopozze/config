###############################################################################
remote_dir  = "/storage/B34A-17F7/MUSIC/" #Change this to SET REMOTE PATH
local_dir   = "/media/NAS/AUDIO/MUSIC/"   #Change this to SET LOCAL PATH
mega_dir    = "/BACKUP/Music"            #Change this to SET MEGA REMOTE PATH
###############################################################################

import sys, os, subprocess

def help_you():
    print ("\n CLI utily to transfer stuff from pc to android device using adb", 
           "\n ADB:",  
           "\n\t -d --delete  Delete old files to remote", 
           "\n\t -g --get Download from ",  remote_dir, 
           "\n\t -p --put Upload from ",  local_dir, 
           "\n\t -m --mega Mega")

def checkXorg():
    process = subprocess.check_output("ps -e | grep X | awk \'{print $4}\'", shell=True).decode("utf-8")
    if(process):
        return True
    else: return False


param_num = len(sys.argv)

if param_num ==  2:
#ADB
    if sys.argv[1] == "-g" or sys.argv[1] == "--get":
       print("remote -> local \n ")
       os.system("adb-sync --reverse " + remote_dir + " " + local_dir)
    elif sys.argv[1] == "-p" or sys.argv[1] == "--put":
       print("local -> remote \n")
       os.system("adb-sync " + local_dir + " " + remote_dir)
    elif sys.argv[1] == "-d" or sys.argv[1] == "--delete":
        print("delete old files on remote \n")
        os.system("adb-sync --delete " + local_dir + " " + remote_dir)
    elif sys.argv[1] == "-d" or sys.argv[1] == "--delete":
        print("delete old files on remote \n")
        os.system("adb-sync --delete " + local_dir + " " + remote_dir)
#MEGA
    elif sys.argv[1] == "-m" or sys.argv[1] == "--mega":
        if checkXorg():
            os.system("megasync")
        else: print("Megasync is allowed only on X, start Xorg")

#HELP
    elif sys.argv[1] == "-h" or sys.argv[1] == "--help": 
       help_you()
#GENERIC ERROR
    else:
        help_you()

elif param_num < 2:
    print ("Too few arguments.")
    help_you()
elif param_num > 2:
    print ("Too many arguments.")
    help_you()
