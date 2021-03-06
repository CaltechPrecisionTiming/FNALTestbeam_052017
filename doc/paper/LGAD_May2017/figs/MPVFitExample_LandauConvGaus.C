void MPVFitExample_LandauConvGaus()
{
//=========Macro generated from canvas: cv/cv
//=========  (Tue Feb 20 19:41:20 2018) by ROOT version6.08/05
   TCanvas *cv = new TCanvas("cv", "cv",731,81,800,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cv->Range(-0.025,-7.908777,0.225,71.17899);
   cv->SetFillColor(0);
   cv->SetBorderMode(0);
   cv->SetBorderSize(2);
   cv->SetFrameBorderMode(0);
   cv->SetFrameBorderMode(0);
   
   TH1D *frame_4345f80__2 = new TH1D("frame_4345f80__2","A RooPlot of \"Amp\"",100,0,0.5);
   frame_4345f80__2->SetBinContent(1,63.27021);
   frame_4345f80__2->SetMaximum(63.27021);
   frame_4345f80__2->SetEntries(1);
   frame_4345f80__2->SetDirectory(0);
   frame_4345f80__2->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_4345f80__2->SetLineColor(ci);
   frame_4345f80__2->GetXaxis()->SetTitle("Amplitude [V]");
   frame_4345f80__2->GetXaxis()->SetRange(1,40);
   frame_4345f80__2->GetXaxis()->SetLabelFont(42);
   frame_4345f80__2->GetXaxis()->SetLabelSize(0.035);
   frame_4345f80__2->GetXaxis()->SetTitleSize(0.035);
   frame_4345f80__2->GetXaxis()->SetTitleOffset(1.3);
   frame_4345f80__2->GetXaxis()->SetTitleFont(42);
   frame_4345f80__2->GetYaxis()->SetTitle("Events / ( 0.005 V )");
   frame_4345f80__2->GetYaxis()->SetLabelFont(42);
   frame_4345f80__2->GetYaxis()->SetLabelSize(0.035);
   frame_4345f80__2->GetYaxis()->SetTitleSize(0.035);
   frame_4345f80__2->GetYaxis()->SetTitleOffset(1.3);
   frame_4345f80__2->GetYaxis()->SetTitleFont(42);
   frame_4345f80__2->GetZaxis()->SetLabelFont(42);
   frame_4345f80__2->GetZaxis()->SetLabelSize(0.035);
   frame_4345f80__2->GetZaxis()->SetTitleSize(0.035);
   frame_4345f80__2->GetZaxis()->SetTitleFont(42);
   frame_4345f80__2->Draw("FUNC");
   
   Double_t h_data_fx3001[100] = {
   0.0025,
   0.0075,
   0.0125,
   0.0175,
   0.0225,
   0.0275,
   0.0325,
   0.0375,
   0.0425,
   0.0475,
   0.0525,
   0.0575,
   0.0625,
   0.0675,
   0.0725,
   0.0775,
   0.0825,
   0.0875,
   0.0925,
   0.0975,
   0.1025,
   0.1075,
   0.1125,
   0.1175,
   0.1225,
   0.1275,
   0.1325,
   0.1375,
   0.1425,
   0.1475,
   0.1525,
   0.1575,
   0.1625,
   0.1675,
   0.1725,
   0.1775,
   0.1825,
   0.1875,
   0.1925,
   0.1975,
   0.2025,
   0.2075,
   0.2125,
   0.2175,
   0.2225,
   0.2275,
   0.2325,
   0.2375,
   0.2425,
   0.2475,
   0.2525,
   0.2575,
   0.2625,
   0.2675,
   0.2725,
   0.2775,
   0.2825,
   0.2875,
   0.2925,
   0.2975,
   0.3025,
   0.3075,
   0.3125,
   0.3175,
   0.3225,
   0.3275,
   0.3325,
   0.3375,
   0.3425,
   0.3475,
   0.3525,
   0.3575,
   0.3625,
   0.3675,
   0.3725,
   0.3775,
   0.3825,
   0.3875,
   0.3925,
   0.3975,
   0.4025,
   0.4075,
   0.4125,
   0.4175,
   0.4225,
   0.4275,
   0.4325,
   0.4375,
   0.4425,
   0.4475,
   0.4525,
   0.4575,
   0.4625,
   0.4675,
   0.4725,
   0.4775,
   0.4825,
   0.4875,
   0.4925,
   0.4975};
   Double_t h_data_fy3001[100] = {
   0,
   0,
   0,
   0,
   2,
   8,
   20,
   44,
   52,
   27,
   26,
   12,
   8,
   5,
   4,
   5,
   5,
   3,
   4,
   1,
   0,
   3,
   1,
   0,
   1,
   0,
   0,
   0,
   2,
   1,
   0,
   1,
   0,
   0,
   0,
   0,
   1,
   0,
   1,
   0,
   0,
   0,
   0,
   0,
   1,
   1,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t h_data_felx3001[100] = {
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025};
   Double_t h_data_fely3001[100] = {
   0,
   0,
   0,
   0,
   1.291815,
   2.768386,
   4.434448,
   6.60794,
   7.187836,
   5.163771,
   5.066015,
   3.415266,
   2.768386,
   2.159691,
   1.914339,
   2.159691,
   2.159691,
   1.632705,
   1.914339,
   0.8272462,
   0,
   1.632705,
   0.8272462,
   0,
   0.8272462,
   0,
   0,
   0,
   1.291815,
   0.8272462,
   0,
   0.8272462,
   0,
   0,
   0,
   0,
   0.8272462,
   0,
   0.8272462,
   0,
   0,
   0,
   0,
   0,
   0.8272462,
   0.8272462,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t h_data_fehx3001[100] = {
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025,
   0.0025};
   Double_t h_data_fehy3001[100] = {
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   2.63786,
   3.945142,
   5.546519,
   7.68351,
   8.257346,
   6.260244,
   6.164324,
   4.559819,
   3.945142,
   3.382473,
   3.162753,
   3.382473,
   3.382473,
   2.918186,
   3.162753,
   2.299527,
   1.147874,
   2.918186,
   2.299527,
   1.147874,
   2.299527,
   1.147874,
   1.147874,
   1.147874,
   2.63786,
   2.299527,
   1.147874,
   2.299527,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   2.299527,
   1.147874,
   2.299527,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   2.299527,
   2.299527,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874,
   1.147874};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(100,h_data_fx3001,h_data_fy3001,h_data_felx3001,h_data_fehx3001,h_data_fely3001,h_data_fehy3001);
   grae->SetName("h_data");
   grae->SetTitle("Histogram of data_plot__amplitude");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(8);
   
   TH1F *Graph_h_data3001 = new TH1F("Graph_h_data3001","Histogram of data_plot__amplitude",100,0,0.55);
   Graph_h_data3001->SetMinimum(0);
   Graph_h_data3001->SetMaximum(66.28308);
   Graph_h_data3001->SetDirectory(0);
   Graph_h_data3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_h_data3001->SetLineColor(ci);
   Graph_h_data3001->GetXaxis()->SetLabelFont(42);
   Graph_h_data3001->GetXaxis()->SetLabelSize(0.035);
   Graph_h_data3001->GetXaxis()->SetTitleSize(0.035);
   Graph_h_data3001->GetXaxis()->SetTitleFont(42);
   Graph_h_data3001->GetYaxis()->SetLabelFont(42);
   Graph_h_data3001->GetYaxis()->SetLabelSize(0.035);
   Graph_h_data3001->GetYaxis()->SetTitleSize(0.035);
   Graph_h_data3001->GetYaxis()->SetTitleFont(42);
   Graph_h_data3001->GetZaxis()->SetLabelFont(42);
   Graph_h_data3001->GetZaxis()->SetLabelSize(0.035);
   Graph_h_data3001->GetZaxis()->SetTitleSize(0.035);
   Graph_h_data3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_h_data3001);
   
   grae->Draw("p");
   
   Double_t lxg_ext_Norm[amplitude]_Range[Full]_NormRange[Full]_fx1[140] = {
   0,
   0.005,
   0.01,
   0.015,
   0.0175,
   0.02,
   0.0225,
   0.02375,
   0.025,
   0.02625,
   0.0275,
   0.028125,
   0.02875,
   0.029375,
   0.03,
   0.030625,
   0.03125,
   0.031875,
   0.0325,
   0.035,
   0.0375,
   0.038125,
   0.03875,
   0.039375,
   0.04,
   0.040625,
   0.04125,
   0.041875,
   0.0425,
   0.043125,
   0.04375,
   0.044375,
   0.045,
   0.045625,
   0.04625,
   0.046875,
   0.0475,
   0.05,
   0.0525,
   0.05375,
   0.055,
   0.05625,
   0.0575,
   0.05875,
   0.06,
   0.06125,
   0.0625,
   0.06375,
   0.065,
   0.06625,
   0.0675,
   0.07,
   0.0725,
   0.075,
   0.08,
   0.085,
   0.09,
   0.095,
   0.1,
   0.105,
   0.11,
   0.115,
   0.12,
   0.125,
   0.13,
   0.135,
   0.14,
   0.145,
   0.15,
   0.155,
   0.16,
   0.165,
   0.17,
   0.175,
   0.18,
   0.185,
   0.19,
   0.195,
   0.2,
   0.205,
   0.21,
   0.215,
   0.22,
   0.225,
   0.23,
   0.235,
   0.24,
   0.245,
   0.25,
   0.255,
   0.26,
   0.265,
   0.27,
   0.275,
   0.28,
   0.285,
   0.29,
   0.295,
   0.3,
   0.305,
   0.31,
   0.315,
   0.32,
   0.325,
   0.33,
   0.335,
   0.34,
   0.345,
   0.35,
   0.355,
   0.36,
   0.365,
   0.37,
   0.375,
   0.38,
   0.385,
   0.39,
   0.395,
   0.4,
   0.405,
   0.41,
   0.415,
   0.42,
   0.425,
   0.43,
   0.435,
   0.44,
   0.445,
   0.45,
   0.455,
   0.46,
   0.465,
   0.47,
   0.475,
   0.48,
   0.485,
   0.49,
   0.495,
   0.5,
   0.5};
   Double_t lxg_ext_Norm[amplitude]_Range[Full]_NormRange[Full]_fy1[140] = {
   0,
   2.135724e-06,
   0.0002924734,
   0.01448428,
   0.03708947,
   0.3061241,
   0.7424082,
   1.712833,
   3.000895,
   4.606595,
   6.529933,
   8.115928,
   9.893602,
   11.86295,
   14.02399,
   16.3767,
   18.92109,
   21.65715,
   24.5849,
   33.97888,
   43.6172,
   44.76022,
   45.62856,
   46.22224,
   46.54125,
   46.58559,
   46.35526,
   45.85025,
   45.07058,
   44.34459,
   43.41689,
   42.28749,
   40.95639,
   39.42358,
   37.68907,
   35.75285,
   33.61493,
   27.81889,
   21.97737,
   19.67785,
   17.62227,
   15.81064,
   14.24296,
   12.79028,
   11.52998,
   10.46204,
   9.586477,
   8.707303,
   7.942106,
   7.290887,
   6.753646,
   5.72627,
   4.958255,
   4.287753,
   3.312303,
   2.625744,
   2.126905,
   1.754474,
   1.469851,
   1.247902,
   1.071763,
   0.9298147,
   0.8138606,
   0.7179953,
   0.6378842,
   0.5702914,
   0.5127641,
   0.4634173,
   0.4207842,
   0.3837103,
   0.3512774,
   0.3227478,
   0.2975242,
   0.2751185,
   0.255129,
   0.2372226,
   0.2211215,
   0.2065925,
   0.1934385,
   0.1814924,
   0.1706116,
   0.1606737,
   0.1515734,
   0.1432197,
   0.1355335,
   0.1284459,
   0.1218965,
   0.1158326,
   0.1102074,
   0.1049799,
   0.1001135,
   0.09557602,
   0.09133846,
   0.08737511,
   0.08366289,
   0.08018111,
   0.07691116,
   0.07383626,
   0.07094126,
   0.06821244,
   0.06563737,
   0.06320475,
   0.06090429,
   0.05872664,
   0.05666322,
   0.05470621,
   0.05284844,
   0.05108334,
   0.04940486,
   0.04780744,
   0.04628596,
   0.04483569,
   0.04345227,
   0.04213167,
   0.04087016,
   0.03966426,
   0.03851076,
   0.03740669,
   0.03634926,
   0.03533589,
   0.03436417,
   0.03343185,
   0.03253685,
   0.03167719,
   0.03085105,
   0.03005671,
   0.02929257,
   0.02855711,
   0.02784892,
   0.02716667,
   0.02650911,
   0.02587508,
   0.02526345,
   0.0246732,
   0.02410333,
   0.02355293,
   0.02302112,
   0.02250705,
   0.02219326,
   0.02219326};
   TGraph *graph = new TGraph(140,lxg_ext_Norm[amplitude]_Range[Full]_NormRange[Full]_fx1,lxg_ext_Norm[amplitude]_Range[Full]_NormRange[Full]_fy1);
   graph->SetName("lxg_ext_Norm[amplitude]_Range[Full]_NormRange[Full]");
   graph->SetTitle("Projection of extLxG");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(4);
   
   TH1F *Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1 = new TH1F("Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1","Projection of extLxG",140,0,0.55);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->SetMinimum(0);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->SetMaximum(51.24415);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->SetDirectory(0);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->SetLineColor(ci);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetXaxis()->SetLabelFont(42);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetXaxis()->SetLabelSize(0.035);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetXaxis()->SetTitleSize(0.035);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetXaxis()->SetTitleFont(42);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetYaxis()->SetLabelFont(42);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetYaxis()->SetLabelSize(0.035);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetYaxis()->SetTitleSize(0.035);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetYaxis()->SetTitleFont(42);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetZaxis()->SetLabelFont(42);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetZaxis()->SetLabelSize(0.035);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetZaxis()->SetTitleSize(0.035);
   Graph_lxg_ext_NormoBamplitudecB_RangeoBFullcB_NormRangeoBFullcB1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_lxg_ext_Norm[amplitude]_Range[Full]_NormRange[Full]1);
   
   graph->Draw("l");
   
   TH1D *frame_4345f80__3 = new TH1D("frame_4345f80__3","A RooPlot of \"Amp\"",100,0,0.5);
   frame_4345f80__3->SetBinContent(1,63.27021);
   frame_4345f80__3->SetMaximum(63.27021);
   frame_4345f80__3->SetEntries(1);
   frame_4345f80__3->SetDirectory(0);
   frame_4345f80__3->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_4345f80__3->SetLineColor(ci);
   frame_4345f80__3->GetXaxis()->SetTitle("Amplitude [V]");
   frame_4345f80__3->GetXaxis()->SetRange(1,40);
   frame_4345f80__3->GetXaxis()->SetLabelFont(42);
   frame_4345f80__3->GetXaxis()->SetLabelSize(0.035);
   frame_4345f80__3->GetXaxis()->SetTitleSize(0.035);
   frame_4345f80__3->GetXaxis()->SetTitleOffset(1.3);
   frame_4345f80__3->GetXaxis()->SetTitleFont(42);
   frame_4345f80__3->GetYaxis()->SetTitle("Events / ( 0.005 V )");
   frame_4345f80__3->GetYaxis()->SetLabelFont(42);
   frame_4345f80__3->GetYaxis()->SetLabelSize(0.035);
   frame_4345f80__3->GetYaxis()->SetTitleSize(0.035);
   frame_4345f80__3->GetYaxis()->SetTitleOffset(1.3);
   frame_4345f80__3->GetYaxis()->SetTitleFont(42);
   frame_4345f80__3->GetZaxis()->SetLabelFont(42);
   frame_4345f80__3->GetZaxis()->SetLabelSize(0.035);
   frame_4345f80__3->GetZaxis()->SetTitleSize(0.035);
   frame_4345f80__3->GetZaxis()->SetTitleFont(42);
   frame_4345f80__3->Draw("AXISSAME");
   cv->Modified();
   cv->cd();
   cv->SetSelected(cv);
}
