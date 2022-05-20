int main(int argc, char *argv, char *envp)
{
    char buildin[7][6] = 
    {
        "echo"
        "cd"
        "pwd"
        "export"
        "unset"
        "env"
        "exit"
    };
    if (argv[2] == "echo")
        ft_echo();
    if (argv[2] == "cd")
        ft_cd();
    if (argv[2] == "pwd")
        ft_pwd();
    if (argv[2] == "export")
        ft_export();
    if (argv[2] == "unset")
        ft_unset();
    if (argv[2] == "env")
        ft_env();
    if (argv[2] == "exit")
        ft_exit();
}