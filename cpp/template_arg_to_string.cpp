inline std::string const& to_string(std::string const& s) { return s; }

template<typename... Args>
std::string template_arg_to_string(Args const&... args)
{
    std::string result;
    using ::to_string;
    using std::to_string;
    int unpack[]{0, (result += to_string(args), 0)...};
    static_cast<void>(unpack);
    return result;
}
