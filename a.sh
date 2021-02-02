get_screen_size()
{
    xdpyinfo | awk '/dimensions:/ { print $2; exit }'
}