return {
  {
    "neovim/nvim-lspconfig",
    opts = {
      servers = {
        typst_lsp = {
          settings = {
            exportPdf = "never",
          },
        },
      },
      setup = {
        typst_lsp = function() end,
      },
    },
  },
}
