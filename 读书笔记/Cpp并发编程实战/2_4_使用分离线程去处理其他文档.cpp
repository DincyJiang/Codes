void edit_document(std::string const& filename) {
    open_document_and_display_gui(filename);

    while (!done_editing()) {
        user_command cmd = get_user_input();
        if (cmd.type == open_new_document) {
            std::string const new_name = get_filename_from_user();
            std::thread t(edit_document, new_name);  // 如果用户选择打开一个新文档，需要启动一个新线程去打开新文档
            t.detach();  // 并分离线程
        } else {
            process_user_input(cmd);
        }
    }
}