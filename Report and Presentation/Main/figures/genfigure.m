% V = [1 3 6]
% 
% for idx = V 
%     VSI_AMP = idx
%     sim("genpath_simulation")
%     runIDs = Simulink.sdi.getAllRunIDs
%     runID = runIDs(end)
%     simDataset = Simulink.sdi.exportRun(runID)
%     printfigure(sprintf("%dV",idx),simDataset)
% end

L = [5 10 20]

for idx = L 
    RL_L = idx*1e-3
    sim("genpath_simulation")
    runIDs = Simulink.sdi.getAllRunIDs
    runID = runIDs(end)
    simDataset = Simulink.sdi.exportRun(runID)
    printfigure(sprintf("%dmH",idx),simDataset)
end