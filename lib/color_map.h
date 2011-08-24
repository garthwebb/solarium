
#ifndef __COLORMAP_H__
#define __COLORMAP_H__

#define NUM_MAPS 11
#define COLOR_MAP_SIZE 181

#define COLOR_MAP_INIT {\
{{250,253,244},{247,251,243},{245,250,242},{243,248,241},{241,247,241},{239,246,240},{236,244,239},{234,243,238},{232,242,238},{230,240,237},{228,239,236},{225,238,235},{223,236,235},{221,235,234},{219,234,233},{217,232,233},{217,233,233},{215,232,232},{214,231,231},{212,231,230},{211,230,229},{209,229,229},{208,229,228},{206,228,227},{205,227,226},{203,227,226},{202,226,225},{200,226,224},{199,225,223},{197,224,223},{196,224,222},{194,223,221},{193,222,220},{192,222,219},{190,221,219},{189,220,218},{187,220,217},{186,219,216},{184,219,216},{183,218,215},{181,217,214},{180,217,213},{178,216,213},{177,215,212},{175,215,211},{174,214,210},{172,214,209},{173,214,210},{170,212,209},{167,210,208},{164,208,207},{161,207,206},{158,205,205},{155,203,204},{152,201,203},{149,200,202},{146,198,201},{143,196,200},{140,194,199},{137,193,198},{134,191,197},{131,189,196},{128,188,195},{128,188,196},{125,186,194},{122,184,193},{119,182,191},{117,180,190},{114,179,188},{111,177,187},{108,175,185},{106,173,184},{103,172,183},{100,170,181},{97,168,180},{95,166,178},{92,165,177},{89,163,175},{86,161,174},{84,159,173},{81,157,171},{78,156,170},{76,154,168},{73,152,167},{70,150,165},{67,149,164},{65,147,163},{62,145,161},{59,143,160},{56,142,158},{54,140,157},{51,138,155},{48,136,154},{45,134,152},{46,135,153},{46,135,153},{46,135,153},{47,135,153},{47,135,153},{48,135,153},{48,135,154},{49,135,154},{49,135,154},{49,135,154},{50,135,154},{50,136,154},{51,136,155},{51,136,155},{52,136,155},{52,136,155},{53,136,155},{53,136,156},{53,136,156},{54,136,156},{54,136,156},{55,137,156},{55,137,156},{56,137,157},{56,137,157},{56,137,157},{57,137,157},{57,137,157},{58,137,158},{58,137,158},{59,137,158},{59,138,158},{60,138,158},{60,138,158},{60,138,159},{61,138,159},{61,138,159},{62,138,159},{62,138,159},{63,138,160},{63,138,160},{64,139,160},{64,139,160},{64,139,160},{65,139,160},{65,139,161},{66,139,161},{66,139,161},{67,139,161},{67,139,161},{67,139,162},{68,140,162},{71,142,163},{75,145,165},{79,148,167},{82,151,169},{86,154,171},{90,157,173},{93,160,174},{97,163,176},{101,166,178},{105,169,180},{108,171,182},{112,174,184},{116,177,186},{119,180,187},{123,183,189},{127,186,191},{130,189,193},{134,192,195},{138,195,197},{142,198,198},{142,198,199},{144,199,199},{146,200,200},{148,201,201},{151,202,201},{153,203,202},{155,204,203},{158,205,203},{160,206,204},{162,207,205},{165,208,205},{167,209,206},{169,210,207},{171,211,208}},\
{{251,253,247},{239,241,237},{227,230,226},{215,218,216},{203,207,206},{191,196,195},{189,195,195},{185,192,193},{182,190,191},{179,187,190},{176,184,188},{172,182,186},{168,179,185},{165,176,183},{162,174,181},{159,171,180},{157,170,179},{156,169,178},{155,168,178},{154,169,177},{153,168,177},{152,168,178},{151,168,177},{150,167,177},{149,167,177},{148,167,177},{147,167,177},{146,167,177},{145,166,177},{144,166,177},{143,166,177},{142,166,177},{142,165,177},{141,166,176},{140,165,177},{139,165,177},{138,165,176},{137,164,176},{136,165,177},{135,164,176},{134,164,176},{133,164,176},{132,163,176},{131,163,176},{130,163,176},{130,163,176},{128,163,175},{129,163,177},{127,162,176},{125,161,176},{123,160,176},{121,159,176},{119,158,175},{117,157,175},{116,156,175},{114,156,175},{112,155,175},{111,154,175},{109,154,176},{107,154,176},{106,153,176},{104,152,176},{102,152,176},{103,153,178},{101,152,177},{99,151,177},{98,150,177},{97,150,177},{95,149,177},{94,149,177},{92,148,176},{91,147,176},{89,147,177},{88,146,176},{86,146,176},{85,145,176},{83,145,176},{82,144,175},{80,143,175},{79,142,175},{79,143,175},{79,145,176},{79,146,176},{79,147,177},{79,148,177},{79,149,178},{80,150,179},{80,151,179},{80,152,180},{79,154,180},{80,155,181},{80,156,181},{80,157,182},{80,158,182},{83,161,184},{83,161,185},{82,160,184},{82,159,183},{81,158,182},{82,158,181},{81,157,181},{81,156,180},{80,155,179},{80,154,178},{80,154,177},{79,154,176},{79,153,176},{79,152,175},{79,151,174},{78,150,173},{78,150,172},{78,149,172},{77,148,171},{77,147,170},{77,146,169},{77,146,168},{76,146,167},{76,145,167},{76,144,166},{75,143,165},{75,142,164},{75,142,163},{75,141,163},{74,140,162},{74,139,161},{74,139,160},{74,138,159},{73,137,158},{73,137,158},{73,136,157},{72,135,156},{72,134,155},{72,134,154},{72,133,154},{71,132,153},{71,132,152},{71,131,151},{70,130,150},{70,129,150},{70,129,149},{70,128,148},{69,127,147},{69,126,146},{69,125,146},{68,125,145},{68,125,144},{70,125,144},{72,126,145},{74,127,145},{75,129,145},{77,130,146},{79,131,146},{81,132,146},{83,134,146},{85,135,147},{87,136,147},{88,136,148},{90,138,148},{93,139,148},{94,140,148},{96,141,149},{98,143,149},{100,144,149},{102,145,150},{104,146,150},{106,147,150},{105,147,150},{106,146,149},{107,146,149},{107,146,148},{109,146,147},{110,146,147},{110,146,147},{112,146,146},{113,146,146},{113,145,145},{115,145,144},{115,145,144},{116,145,144},{117,145,144}},\
{{253,254,251},{231,232,231},{209,210,210},{187,189,191},{165,167,171},{143,146,151},{142,146,151},{137,141,148},{132,138,145},{128,134,143},{124,129,140},{119,126,137},{114,122,135},{110,117,132},{105,114,129},{101,110,127},{97,107,125},{97,106,124},{96,106,125},{96,107,125},{95,106,126},{95,107,127},{94,107,127},{94,107,128},{94,107,128},{93,108,129},{93,108,130},{92,108,130},{92,108,131},{91,108,132},{91,109,132},{91,109,133},{91,109,134},{90,110,134},{90,109,135},{89,110,136},{89,110,136},{88,110,136},{88,111,138},{88,110,138},{87,111,138},{87,111,139},{86,111,140},{86,111,140},{85,111,141},{86,112,142},{85,112,142},{85,112,144},{84,112,144},{83,112,144},{82,112,145},{81,112,146},{81,111,146},{80,111,146},{80,111,147},{79,112,148},{79,113,150},{79,113,151},{78,114,153},{78,115,154},{78,115,155},{77,115,156},{77,116,158},{78,118,160},{77,118,161},{77,118,162},{77,119,163},{77,120,164},{77,120,166},{77,121,167},{76,121,168},{76,121,169},{76,122,171},{76,123,171},{75,124,173},{75,124,174},{75,125,175},{75,125,176},{74,125,177},{74,125,177},{77,129,179},{80,134,182},{83,138,184},{86,142,187},{88,146,189},{91,150,192},{95,154,195},{98,158,197},{101,162,200},{103,166,202},{106,170,205},{109,174,208},{112,178,210},{115,182,213},{120,187,216},{120,187,217},{118,185,215},{117,184,213},{116,182,211},{116,181,209},{114,179,208},{113,177,206},{112,176,204},{111,174,202},{110,173,200},{109,172,198},{108,170,197},{107,168,195},{106,167,193},{105,165,191},{104,164,189},{103,162,188},{102,160,186},{101,159,184},{100,157,182},{99,156,180},{98,155,178},{97,153,177},{96,151,175},{95,149,173},{94,148,171},{93,147,170},{92,145,168},{91,143,166},{90,142,164},{89,140,162},{88,139,161},{87,137,159},{86,136,157},{85,134,155},{83,132,154},{83,131,152},{82,130,150},{81,128,148},{79,126,147},{79,125,145},{78,123,143},{76,122,141},{75,120,140},{75,119,138},{74,117,136},{72,115,134},{72,114,132},{71,112,131},{69,111,129},{68,110,127},{69,108,125},{69,108,125},{69,107,123},{68,107,122},{69,106,121},{69,105,120},{69,105,118},{69,105,117},{69,104,116},{69,103,114},{69,102,114},{69,102,112},{70,101,111},{69,100,109},{69,100,109},{69,100,107},{70,99,106},{70,98,105},{70,97,104},{70,97,102},{69,96,101},{68,94,99},{68,93,98},{67,92,96},{67,90,94},{67,89,92},{66,88,91},{66,87,89},{66,86,88},{65,84,86},{65,83,84},{64,82,83},{64,80,81},{63,79,80}},\
{{255,255,255},{223,223,225},{191,191,195},{159,160,166},{127,128,136},{95,97,107},{95,97,107},{89,91,103},{83,86,99},{77,81,96},{72,75,92},{66,70,89},{60,65,85},{55,59,81},{49,54,78},{43,49,74},{37,44,71},{38,44,71},{38,44,72},{38,45,73},{38,45,75},{38,46,76},{38,47,77},{38,47,79},{39,48,80},{39,49,81},{39,49,83},{39,50,84},{39,50,85},{39,51,87},{39,52,88},{40,52,89},{40,53,91},{40,54,92},{40,54,93},{40,55,95},{40,55,96},{40,56,97},{41,57,99},{41,57,100},{41,58,101},{41,59,103},{41,59,104},{41,60,105},{41,60,107},{42,61,108},{42,62,109},{42,62,111},{42,63,112},{42,64,113},{42,64,115},{42,65,116},{43,65,117},{43,66,118},{44,67,120},{45,69,122},{46,71,125},{47,72,127},{48,74,130},{49,76,132},{50,78,135},{51,79,137},{52,81,140},{53,83,142},{54,84,145},{55,86,147},{57,88,150},{58,90,152},{59,91,155},{60,93,157},{61,95,160},{62,96,162},{63,98,165},{64,100,167},{65,102,170},{66,103,172},{67,105,175},{68,107,177},{69,108,179},{70,109,180},{75,116,184},{81,123,189},{87,130,193},{93,137,198},{98,144,202},{104,151,207},{110,158,212},{116,165,216},{122,172,221},{127,179,225},{133,186,230},{139,193,235},{145,200,239},{151,207,244},{157,214,248},{157,214,249},{155,211,246},{153,209,243},{151,206,240},{150,204,237},{148,202,235},{146,199,232},{144,197,229},{143,194,226},{141,192,224},{139,190,221},{137,187,218},{136,185,215},{134,183,213},{132,180,210},{130,178,207},{129,175,204},{127,173,201},{125,171,199},{123,168,196},{122,166,193},{120,164,190},{118,161,188},{116,159,185},{115,156,182},{113,154,179},{111,152,177},{109,149,174},{108,147,171},{106,145,168},{104,142,165},{102,140,163},{101,137,160},{99,135,157},{97,133,154},{95,130,152},{94,128,149},{92,126,146},{90,123,143},{88,121,141},{87,118,138},{85,116,135},{83,114,132},{81,111,130},{80,109,127},{78,107,124},{76,104,121},{75,102,118},{73,99,116},{71,97,113},{69,95,110},{68,92,107},{66,90,105},{64,87,102},{62,85,99},{61,83,96},{59,80,94},{57,78,91},{55,76,88},{54,73,85},{52,71,82},{50,68,80},{48,66,77},{47,64,74},{45,61,71},{43,59,69},{41,57,66},{40,54,63},{38,52,60},{36,49,58},{34,47,55},{33,45,52},{31,42,49},{29,40,47},{27,38,44},{26,35,41},{24,33,38},{22,30,35},{20,28,33},{19,26,30},{17,23,27},{15,21,24},{13,19,22},{12,16,19},{10,14,16}},\
{{255,255,255},{230,230,233},{206,206,211},{181,183,191},{157,159,169},{133,136,148},{133,136,148},{122,126,144},{111,118,139},{101,109,135},{91,100,130},{80,92,126},{76,88,124},{72,84,120},{68,80,118},{63,76,115},{59,72,113},{59,72,112},{59,71,113},{58,71,113},{58,71,114},{57,71,114},{57,71,114},{57,71,115},{57,71,116},{56,71,116},{56,71,117},{55,71,117},{55,70,117},{55,71,118},{54,71,119},{54,70,119},{54,71,120},{54,71,121},{54,71,121},{53,71,122},{53,71,123},{53,72,123},{53,72,124},{53,72,125},{53,72,125},{52,73,126},{52,72,127},{52,73,127},{51,73,128},{52,73,129},{52,73,129},{51,73,130},{51,74,131},{51,74,131},{50,74,132},{50,74,133},{51,74,133},{50,74,133},{51,75,135},{51,76,136},{51,77,137},{52,78,139},{52,79,140},{53,80,141},{53,81,143},{53,81,144},{54,82,146},{54,83,147},{55,84,149},{56,86,151},{57,87,153},{58,88,154},{58,89,156},{59,90,157},{60,92,159},{60,92,161},{61,94,163},{62,95,164},{62,96,166},{63,97,167},{64,98,169},{64,100,171},{65,100,172},{66,101,173},{69,106,175},{73,110,179},{77,115,181},{81,120,185},{84,124,187},{88,129,191},{92,134,194},{96,138,197},{100,143,200},{104,148,203},{108,152,206},{112,157,209},{116,162,212},{120,166,215},{124,171,218},{124,171,219},{122,169,217},{121,168,215},{120,166,213},{119,164,211},{118,163,209},{116,161,207},{115,160,205},{114,158,203},{113,156,202},{112,155,200},{110,153,198},{110,152,196},{108,150,195},{107,148,193},{106,147,191},{105,145,189},{104,144,187},{102,142,185},{101,140,183},{100,139,181},{99,138,179},{98,136,178},{96,134,176},{96,132,174},{94,131,172},{93,130,171},{92,128,169},{91,126,167},{90,125,165},{88,123,163},{87,121,160},{86,119,157},{84,117,155},{82,115,152},{81,112,149},{80,111,147},{78,109,144},{76,106,141},{75,105,139},{74,102,136},{72,100,133},{70,98,130},{69,96,128},{68,94,125},{66,92,122},{64,90,119},{63,88,116},{62,86,114},{60,84,111},{58,82,108},{57,79,105},{56,78,103},{54,75,100},{52,73,97},{51,72,94},{50,69,92},{48,67,89},{46,65,86},{45,63,84},{44,61,81},{42,59,78},{41,57,76},{40,55,73},{38,53,70},{36,51,68},{35,49,65},{34,46,62},{32,45,59},{30,42,57},{29,40,54},{28,39,51},{26,36,48},{24,34,46},{23,32,43},{22,30,40},{20,28,37},{18,26,34},{17,24,32},{16,22,29},{14,20,26},{12,18,23},{11,16,21},{10,14,18},{8,12,15}},\
{{255,255,255},{237,238,241},{221,222,228},{204,206,216},{187,190,202},{171,175,190},{171,175,190},{155,162,185},{140,150,179},{125,138,174},{110,125,169},{94,114,164},{93,112,163},{90,109,160},{87,106,158},{84,103,156},{81,101,155},{81,100,154},{80,99,154},{79,98,153},{78,97,153},{77,96,152},{76,96,152},{76,95,152},{75,94,152},{74,94,151},{73,93,151},{72,92,150},{71,91,150},{71,91,150},{69,90,150},{69,89,149},{68,89,149},{68,89,150},{68,88,149},{67,88,149},{66,87,150},{66,88,149},{65,87,149},{65,87,150},{65,87,149},{64,87,149},{63,86,150},{63,86,149},{62,86,149},{62,85,150},{62,85,149},{61,85,149},{60,85,150},{60,84,149},{59,84,149},{59,84,150},{59,83,149},{58,83,149},{58,83,150},{57,83,150},{57,83,150},{57,84,151},{57,84,151},{57,84,151},{56,84,152},{56,84,152},{56,84,152},{56,84,153},{56,85,154},{57,86,155},{57,86,156},{58,87,156},{58,87,157},{58,88,158},{59,89,159},{59,89,160},{59,90,161},{60,90,161},{60,91,162},{60,91,163},{61,92,164},{61,93,165},{61,93,165},{62,93,166},{63,96,167},{65,98,169},{67,100,170},{69,103,172},{71,105,173},{73,107,175},{75,110,176},{77,112,178},{79,114,179},{81,117,181},{83,119,182},{85,121,184},{87,124,185},{89,126,187},{91,128,188},{91,128,189},{90,127,188},{89,127,187},{89,126,186},{88,125,185},{88,124,184},{87,123,183},{86,123,182},{86,122,181},{85,121,180},{85,120,179},{84,119,178},{84,119,177},{83,118,177},{82,117,176},{82,116,175},{81,115,174},{81,115,173},{80,114,172},{79,113,171},{79,112,170},{78,112,169},{78,111,168},{77,110,167},{77,109,166},{76,108,165},{75,108,165},{75,107,164},{74,106,163},{74,105,162},{73,104,161},{72,102,158},{71,101,155},{69,99,153},{68,97,150},{67,95,147},{66,94,145},{64,92,142},{63,90,139},{62,89,137},{61,86,134},{59,85,131},{58,83,128},{57,81,126},{56,79,123},{54,78,120},{53,76,117},{52,74,114},{51,73,112},{49,71,109},{48,69,106},{47,67,104},{46,66,101},{44,64,99},{43,62,96},{42,61,93},{41,58,91},{39,57,88},{38,55,85},{37,53,83},{36,51,80},{35,50,77},{34,48,75},{33,46,72},{31,45,69},{30,43,67},{29,41,64},{28,39,61},{26,38,58},{25,36,56},{24,34,53},{23,33,50},{21,30,47},{20,29,45},{19,27,42},{18,25,39},{16,24,37},{15,22,34},{14,20,31},{13,18,29},{11,17,26},{10,15,23},{9,13,21},{8,12,18},{6,10,15}},\
{{255,255,255},{245,246,250},{236,238,245},{227,230,241},{218,222,236},{209,214,232},{209,214,232},{189,198,226},{169,182,220},{149,167,214},{129,151,208},{109,136,202},{110,136,202},{108,134,200},{107,133,199},{105,131,198},{104,130,197},{103,128,196},{101,127,195},{100,125,193},{99,124,192},{97,122,191},{96,121,190},{95,120,189},{93,118,188},{92,117,187},{91,115,185},{89,114,184},{88,112,183},{87,111,182},{85,109,181},{84,108,180},{83,107,178},{83,107,179},{82,106,178},{81,105,177},{80,104,177},{79,104,176},{78,103,175},{78,102,175},{77,102,174},{76,101,173},{75,100,173},{74,99,172},{73,99,171},{73,98,171},{72,97,170},{71,97,169},{70,96,169},{69,95,168},{68,95,167},{68,94,167},{67,93,166},{66,92,165},{65,92,165},{64,91,164},{63,90,163},{63,90,163},{62,89,162},{61,88,161},{60,88,161},{59,87,160},{58,86,159},{58,85,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{58,86,159},{57,84,156},{56,83,153},{55,81,151},{54,80,148},{53,78,145},{52,77,143},{51,75,140},{50,74,137},{49,73,135},{48,71,132},{47,70,129},{46,68,127},{45,67,124},{44,65,121},{43,64,119},{42,63,116},{41,61,113},{40,60,111},{39,58,108},{38,57,105},{37,55,103},{36,54,100},{35,53,98},{34,51,95},{33,50,92},{32,48,90},{31,47,87},{30,45,84},{29,44,82},{28,42,79},{28,41,76},{27,40,74},{26,38,71},{25,37,68},{24,35,66},{23,34,63},{22,32,60},{21,31,58},{20,30,55},{19,28,52},{18,27,50},{17,25,47},{16,24,45},{15,22,42},{14,21,39},{13,20,37},{12,18,34},{11,17,31},{10,15,29},{9,14,26},{8,12,23},{7,11,21},{6,10,18},{5,8,15}},\
{{242,205,170},{235,203,167},{229,202,165},{223,201,164},{217,200,162},{211,199,161},{211,199,161},{198,189,158},{185,179,156},{171,169,153},{158,159,151},{145,150,148},{146,151,150},{145,150,150},{145,150,151},{143,149,151},{143,149,152},{143,149,153},{141,149,154},{141,148,154},{141,148,155},{139,147,156},{139,147,155},{138,146,156},{136,144,156},{136,143,157},{135,141,157},{133,140,157},{132,139,158},{132,137,158},{130,136,159},{129,135,160},{128,134,160},{128,133,161},{127,132,162},{127,131,163},{126,130,164},{125,130,164},{124,129,165},{124,128,166},{123,127,167},{122,126,167},{121,125,168},{120,124,169},{120,124,170},{119,123,171},{119,122,171},{118,121,172},{117,120,173},{116,119,174},{115,119,174},{115,118,176},{114,117,176},{114,116,176},{111,115,175},{109,113,174},{107,111,172},{105,110,172},{103,108,170},{101,106,169},{98,105,168},{96,103,167},{94,101,166},{92,99,165},{91,99,164},{89,97,164},{87,96,163},{86,95,163},{84,94,162},{83,93,161},{81,91,161},{80,90,160},{78,89,159},{76,88,159},{75,87,158},{73,85,157},{72,84,157},{70,83,156},{68,82,155},{67,81,155},{65,79,154},{64,78,154},{62,77,153},{60,76,152},{59,75,152},{57,73,151},{56,72,150},{54,71,150},{52,70,149},{51,69,148},{49,67,148},{48,66,147},{46,65,146},{44,64,146},{45,64,146},{44,64,145},{44,64,145},{44,64,144},{44,64,144},{44,63,144},{44,63,143},{44,63,143},{44,63,142},{44,63,142},{44,63,141},{44,63,141},{44,63,140},{44,63,140},{44,63,140},{43,63,139},{43,63,139},{43,63,138},{43,62,138},{43,62,137},{43,62,137},{43,62,136},{43,62,136},{43,62,136},{43,62,135},{43,62,135},{43,62,134},{43,62,134},{43,62,133},{42,62,133},{42,61,132},{42,61,132},{42,60,129},{41,59,127},{40,58,125},{39,57,123},{39,56,120},{38,55,119},{37,54,116},{36,53,114},{36,52,112},{35,51,109},{34,50,107},{33,48,105},{33,48,103},{32,46,100},{31,46,99},{31,45,96},{30,43,94},{29,43,92},{28,41,89},{28,41,87},{27,39,85},{26,38,83},{25,38,81},{25,36,79},{24,35,76},{23,34,74},{22,33,72},{22,32,69},{21,31,68},{20,30,65},{20,29,63},{19,28,61},{19,27,58},{18,26,56},{17,25,54},{16,24,52},{16,23,49},{15,22,48},{14,21,45},{14,20,43},{13,19,41},{12,17,38},{11,17,37},{11,15,34},{10,15,32},{9,14,30},{8,12,28},{8,12,25},{7,10,23},{6,10,21},{5,8,18},{5,7,17},{4,7,14},{3,5,12}},\
{{229,155,85},{225,160,85},{222,166,86},{219,172,87},{216,178,88},{213,184,90},{213,184,90},{207,180,90},{201,176,92},{194,172,92},{188,168,94},{182,164,94},{182,166,98},{182,166,100},{183,167,103},{182,168,105},{182,169,108},{183,170,110},{182,171,113},{182,171,115},{183,172,118},{182,173,121},{182,173,121},{181,172,123},{180,170,125},{180,169,127},{179,168,129},{178,167,131},{177,166,133},{177,164,135},{175,163,137},{175,162,140},{174,161,142},{174,160,144},{173,159,146},{173,157,149},{172,156,151},{171,156,153},{170,155,155},{170,154,157},{169,153,160},{168,151,162},{168,150,164},{167,149,166},{167,149,169},{166,148,171},{166,147,173},{165,145,175},{164,144,178},{163,143,180},{163,143,182},{162,142,185},{162,141,186},{162,140,187},{158,138,185},{154,135,184},{151,132,182},{147,130,181},{144,127,179},{141,124,177},{137,122,176},{133,119,174},{130,116,173},{127,114,171},{124,112,170},{120,109,169},{117,107,167},{114,104,167},{111,102,165},{108,100,164},{104,97,163},{102,95,161},{98,92,160},{95,90,159},{92,88,157},{88,85,156},{86,83,155},{82,80,153},{79,78,152},{76,76,151},{73,73,150},{70,71,149},{66,68,147},{63,66,146},{60,64,145},{57,61,143},{54,59,142},{50,56,141},{47,54,139},{44,52,138},{41,49,137},{38,47,135},{34,44,134},{31,42,133},{32,42,133},{31,42,132},{31,42,131},{31,42,130},{31,42,129},{30,41,129},{30,41,127},{30,41,127},{30,41,126},{30,40,125},{30,40,124},{30,40,123},{30,40,122},{30,40,121},{30,40,121},{29,40,119},{29,40,119},{29,40,118},{29,39,117},{28,39,116},{28,39,115},{28,39,114},{28,38,113},{28,38,113},{28,38,111},{28,38,111},{28,38,110},{28,38,109},{28,38,108},{27,38,107},{27,37,106},{27,37,105},{27,36,103},{26,36,101},{25,35,100},{25,34,98},{25,34,96},{24,33,95},{23,33,92},{23,32,91},{23,31,89},{22,31,87},{22,30,85},{21,29,84},{21,29,82},{20,28,80},{20,28,79},{20,27,76},{19,26,75},{18,26,73},{18,25,71},{18,25,69},{17,23,68},{16,23,66},{16,23,64},{16,22,63},{15,21,60},{14,20,59},{14,20,57},{14,19,55},{13,19,54},{13,18,51},{12,17,50},{12,17,48},{12,16,46},{11,15,44},{11,15,43},{10,14,41},{10,14,39},{9,13,38},{9,12,35},{9,12,34},{8,11,32},{7,10,30},{7,10,29},{7,9,27},{6,9,25},{5,8,23},{5,7,22},{5,7,19},{4,6,18},{3,6,16},{3,4,14},{3,4,13},{2,4,11},{2,3,9}},\
{{216,105,0},{216,117,3},{216,130,7},{216,143,11},{216,156,15},{216,169,19},{216,169,19},{216,171,23},{217,173,28},{217,175,32},{218,177,37},{219,179,41},{219,181,46},{220,183,50},{221,185,55},{221,187,59},{222,189,64},{223,191,68},{223,193,73},{224,195,77},{225,197,82},{225,199,86},{226,200,87},{225,198,90},{224,197,94},{224,196,98},{223,195,101},{223,194,105},{222,193,109},{222,191,112},{221,190,116},{221,189,120},{220,188,124},{220,187,127},{219,186,131},{219,184,135},{218,183,138},{218,182,142},{217,181,146},{216,180,149},{216,179,153},{215,177,157},{215,176,160},{214,175,164},{214,174,168},{213,173,172},{213,172,175},{212,170,179},{212,169,183},{211,168,186},{211,167,190},{210,166,194},{210,165,197},{210,165,198},{205,161,196},{200,157,194},{195,154,192},{190,150,190},{186,147,188},{181,143,186},{176,139,184},{171,136,182},{167,132,180},{162,129,178},{157,125,176},{152,121,174},{147,118,172},{143,114,171},{138,111,169},{133,107,167},{128,103,165},{124,100,163},{119,96,161},{114,93,159},{109,89,157},{104,85,155},{100,82,153},{95,78,151},{90,75,149},{85,71,147},{81,67,146},{76,64,144},{71,60,142},{66,57,140},{61,53,138},{57,49,136},{52,46,134},{47,42,132},{42,39,130},{38,35,128},{33,31,126},{28,28,124},{23,24,122},{18,21,120},{19,21,121},{18,20,119},{18,20,118},{18,20,116},{18,20,115},{17,19,114},{17,19,112},{17,19,111},{17,19,110},{17,18,108},{16,18,107},{16,18,106},{16,18,104},{16,17,103},{16,17,102},{15,17,100},{15,17,99},{15,17,98},{15,16,96},{14,16,95},{14,16,94},{14,16,92},{14,15,91},{14,15,90},{13,15,88},{13,15,87},{13,14,86},{13,14,84},{13,14,83},{12,14,82},{12,13,80},{12,13,79},{12,13,77},{12,13,76},{11,13,75},{11,12,73},{11,12,72},{11,12,71},{10,12,69},{10,11,68},{10,11,67},{10,11,65},{10,11,64},{9,10,63},{9,10,61},{9,10,60},{9,10,59},{9,10,57},{8,9,56},{8,9,55},{8,9,53},{8,9,52},{8,8,51},{7,8,49},{7,8,48},{7,8,47},{7,7,45},{6,7,44},{6,7,43},{6,7,41},{6,7,40},{6,6,38},{5,6,37},{5,6,36},{5,6,34},{5,5,33},{5,5,32},{4,5,30},{4,5,29},{4,4,28},{4,4,26},{4,4,25},{3,4,24},{3,3,22},{3,3,21},{3,3,20},{2,3,18},{2,3,17},{2,2,16},{2,2,14},{2,2,13},{1,2,12},{1,1,10},{1,1,9},{1,1,8},{1,1,6}},\
}

#endif