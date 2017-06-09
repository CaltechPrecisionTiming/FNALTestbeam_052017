{
  gROOT->Reset();
  int npoints = 5;
  double bias[]        = {100, 200, 250, 300, 325};
  double bias_err[]    = {0, 0, 0, 0, 0};
  double mpv_ch1[]     = {1.87995e-2, 3.64135e-2, 5.54148e-2, 1.03937e-1, 1.56467e-1};
  double mpv_ch1_err[] = {1.53789e-4, 3.39928e-4, 3.45486e-4, 9.40782e-4, 6.91020e-4};

  double mpv_ch2[]     = {2.02033e-2, 3.82949e-2, 5.90875e-2, 1.08508e-1, 1.65709e-1};
  double mpv_ch2_err[] = {3.76539e-4, 7.37524e-4, 8.78573e-4, 1.16828e-3, 1.48146e-3};

  TGraphErrors* mpv_vs_BV_ch1 = new TGraphErrors(npoints, bias, mpv_ch1, bias_err, mpv_ch1_err);
  TGraphErrors* mpv_vs_BV_ch2 = new TGraphErrors(npoints, bias, mpv_ch2, bias_err, mpv_ch2_err);

  TCanvas* c = new TCanvas("canvas","canvas",600,400);
  mpv_vs_BV_ch1->SetTitle("");
  mpv_vs_BV_ch1->GetXaxis()->SetTitle("Bias voltage [V]");
  mpv_vs_BV_ch1->GetYaxis()->SetTitle("m.p.v [V]");
  mpv_vs_BV_ch1->GetXaxis()->SetTitleSize(0.05);
  mpv_vs_BV_ch1->GetXaxis()->SetTitleOffset(0.87);
  mpv_vs_BV_ch1->GetYaxis()->SetTitleSize(0.05);
  mpv_vs_BV_ch1->GetYaxis()->SetTitleOffset(0.83);
  mpv_vs_BV_ch1->SetMarkerStyle(20);
  mpv_vs_BV_ch1->SetMarkerStyle(kBlue);
  mpv_vs_BV_ch1->SetMarkerSize(0.7);
  mpv_vs_BV_ch1->SetMarkerColor(kBlue);
  mpv_vs_BV_ch1->SetLineColor(kBlue);
  mpv_vs_BV_ch1->SetMarkerStyle(20);
  mpv_vs_BV_ch1->Draw("AP");

  mpv_vs_BV_ch2->SetTitle("");
  mpv_vs_BV_ch2->GetXaxis()->SetTitle("Bias voltage [V]");
  mpv_vs_BV_ch2->GetYaxis()->SetTitle("m.p.v [V]");
  mpv_vs_BV_ch2->GetXaxis()->SetTitleSize(0.05);
  mpv_vs_BV_ch2->GetXaxis()->SetTitleOffset(0.87);
  mpv_vs_BV_ch2->GetYaxis()->SetTitleSize(0.05);
  mpv_vs_BV_ch2->GetYaxis()->SetTitleOffset(0.83);
  mpv_vs_BV_ch2->SetMarkerStyle(20);
  mpv_vs_BV_ch2->SetMarkerStyle(kRed);
  mpv_vs_BV_ch2->SetMarkerSize(0.7);
  mpv_vs_BV_ch2->SetMarkerColor(kRed);
  mpv_vs_BV_ch2->SetLineColor(kRed);
  mpv_vs_BV_ch2->SetMarkerStyle(22);
  mpv_vs_BV_ch2->Draw("P");

  TLegend* leg = new TLegend( 0.2, 0.7, 0.4, 0.8, NULL, "brNDC" );
  leg->SetBorderSize(0);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->AddEntry( mpv_vs_BV_ch1, "left pad", "lep" );
  leg->AddEntry( mpv_vs_BV_ch2, "right pad", "lep" );
  leg->Draw();
}
