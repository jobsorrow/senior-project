function printfigure(filename,simout) 
commanded_phase_voltage = simout{5}.Values
tam_command_mode = simout{12}.Values
line_current  = simout{3}.Values
tam_fqt_output = simout{7}.Values

createfigure(commanded_phase_voltage.Time,commanded_phase_voltage.Data,tam_command_mode.Time,tam_command_mode.Data,line_current.Time,line_current.Data,tam_fqt_output.Data)
exportgraphics(gcf,sprintf("%s.pdf",filename),"contenttype","vector")
end